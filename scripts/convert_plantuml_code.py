import time
from pathlib import Path
from plantuml import PlantUML

GLOB_PATTERN = "../lectures/*/images/*.plantuml"
AMT_RETRIES = 3

def get_all_files(pattern: str = GLOB_PATTERN) -> list[Path]:
    """Get all files matching the glob pattern."""
    script_dir = Path(__file__).resolve().parent
    return list(script_dir.glob(pattern))

def check_if_svg_exits(plantuml_path: Path) -> bool:
    """Check if the corresponding SVG file already exists."""
    svg_path = plantuml_path.with_suffix(".svg")
    return svg_path.exists()

def generate_svg(plantuml_path: Path) -> None:
    pl = PlantUML(url="http://www.plantuml.com/plantuml/svg/")

    attempts = 0
    success = False

    while attempts < AMT_RETRIES and not success:
        attempts += 1
        success = pl.processes_file(plantuml_path, directory=plantuml_path.parent)

        if not success:
            print(f"Attempt {attempts} failed for {plantuml_path}. Retrying...")
            time.sleep(1) # Sometimes the server is too busy --> wait a bit before retrying

    print(f"Generated from {plantuml_path}: {success} in {attempts} attempt(s)")

if __name__ == "__main__":
    for file_path in get_all_files():

        # TODO: store hash or similar to only regenerate if the file has changed
        if not check_if_svg_exits(file_path):
            generate_svg(file_path)