# https://github.com/dougn/python-plantuml/blob/master/plantuml.py
# Converted to Python 3 & changed to svg
from __future__ import annotations

import argparse
import base64
import string
import zlib
from dataclasses import dataclass
from typing import Dict, Optional
from urllib.parse import urlencode, urljoin

import requests

plantuml_alphabet = (
    string.digits + string.ascii_uppercase + string.ascii_lowercase + "-_"
)
base64_alphabet = string.ascii_uppercase + string.ascii_lowercase + string.digits + "+/"

# translation table for bytes
_b64_to_plantuml_table = bytes.maketrans(
    base64_alphabet.encode("ascii"), plantuml_alphabet.encode("ascii")
)


class PlantUMLError(Exception):
    """Error in processing."""

    pass


class PlantUMLConnectionError(PlantUMLError):
    """Error connecting or talking to PlantUML Server."""

    pass


class PlantUMLHTTPError(PlantUMLConnectionError):
    """Request to PlantUML server returned HTTP Error."""

    def __init__(self, response: requests.Response, content: bytes):
        self.response = response
        self.content = content
        message = f"{response.status_code}: {response.reason}"
        super().__init__(message)


def deflate_and_encode(plantuml_text: str) -> str:
    """
    zlib compress the plantuml text and encode it for the plantuml server.
    """
    compressed = zlib.compress(plantuml_text.encode("utf-8"))
    # strip zlib header and checksum as original implementation did
    compressed = compressed[2:-4]
    b64 = base64.b64encode(compressed)
    translated = b64.translate(_b64_to_plantuml_table)
    return translated.decode("ascii")


@dataclass
class PlantUML:
    url: str = "http://www.plantuml.com/plantuml/svg/"
    basic_auth: Optional[Dict[str, str]] = None
    form_auth: Optional[Dict] = None
    session: requests.Session = None

    def __post_init__(self):
        self.session = requests.Session()
        if self.basic_auth:
            # requests will handle basic auth for requests if provided per-request.
            pass

        if self.form_auth:
            login_url = self.form_auth.get("url")
            body = self.form_auth.get("body")
            method = self.form_auth.get("method", "POST").upper()
            headers = self.form_auth.get(
                "headers", {"Content-Type": "application/x-www-form-urlencoded"}
            )
            if not login_url or not isinstance(body, dict):
                raise PlantUMLError("form_auth must include 'url' and 'body' (dict).")
            data = urlencode(body)
            try:
                resp = self.session.request(
                    method, login_url, headers=headers, data=data
                )
            except requests.RequestException as exc:
                raise PlantUMLConnectionError(exc)
            if resp.status_code != 200:
                raise PlantUMLHTTPError(resp, resp.content)
            # session will keep cookies automatically

    def get_url(self, plantuml_text: str) -> str:
        suffix = deflate_and_encode(plantuml_text)
        return urljoin(self.url, suffix)

    def processes(self, plantuml_text: str) -> bytes:
        url = self.get_url(plantuml_text)
        # print(f"Requesting {url} ...")

        try:
            if self.basic_auth:
                resp = self.session.get(
                    url,
                    auth=(
                        self.basic_auth.get("username"),
                        self.basic_auth.get("password"),
                    ),
                )
            else:
                resp = self.session.get(url)
        except requests.RequestException as exc:
            raise PlantUMLConnectionError(exc)
        if resp.status_code != 200:
            raise PlantUMLHTTPError(resp, resp.content)
        return resp.content

    def processes_file(
        self,
        filename: str,
        outfile: Optional[str] = None,
        errorfile: Optional[str] = None,
        directory: str = "",
    ) -> bool:
        import os

        if outfile is None:
            outfile = os.path.splitext(filename)[0] + ".svg"
        if errorfile is None:
            errorfile = os.path.splitext(filename)[0] + "_error.html"
        if directory and not os.path.exists(directory):
            os.makedirs(directory, exist_ok=True)

        with open(filename, "r", encoding="utf-8") as f:
            data = f.read()

        try:
            content = self.processes(data)
        except PlantUMLHTTPError as e:
            with open(os.path.join(directory, errorfile), "wb") as err:
                err.write(
                    e.content
                    if isinstance(e.content, (bytes, bytearray))
                    else str(e.content).encode("utf-8")
                )
            return False

        with open(os.path.join(directory, outfile), "wb") as out:
            out.write(content)
        return True


def _build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Generate images from PlantUML files using a PlantUML server"
    )
    parser.add_argument(
        "files", metavar="filename", nargs="+", help="file(s) to generate images from"
    )
    parser.add_argument(
        "-o", "--out", default="", help="directory to put the files into"
    )
    parser.add_argument(
        "-s",
        "--server",
        default="http://www.plantuml.com/plantuml/svg/",
        help='server to generate from, defaults to "http://www.plantuml.com/plantuml/svg/"',
    )
    parser.add_argument("--basic-user", help="basic auth username")
    parser.add_argument("--basic-pass", help="basic auth password")
    return parser


def main() -> None:
    args = _build_parser().parse_args()
    basic_auth = None
    if args.basic_user or args.basic_pass:
        basic_auth = {
            "username": args.basic_user or "",
            "password": args.basic_pass or "",
        }

    pl = PlantUML(url=args.server, basic_auth=basic_auth)
    results = []
    for filename in args.files:
        success = pl.processes_file(filename, directory=args.out)
        results.append({"filename": filename, "gen_success": success})
    print(results)


if __name__ == "__main__":
    main()
