"""
Script to compile and run a C file.
The output from stdout is printed to the console --> shown like normal Quarto output.
The result object is available for further processing, e.g. to extract data, etc.
"""

import subprocess
import sys
from pathlib import Path

# args must be path to file to compile and run
path = sys.argv[1]

# Shitty way to pass compile options to the script.
# By default optimized with -O3, but for some examples we need to disable optimization

compile_options = "-O3"
args = sys.argv[2:]
args = " ".join(args)

if args:
    if "-O" in args:
        compile_options = args
    else:
        compile_options += " " + args
compile_options = compile_options.split(" ")

source = Path.cwd() / path
executable = str(source.absolute().with_suffix(".out"))

# By default subprocess.run() will open a new console window on Windows, which captures focus and is quite annoying.
# This is surpressed using either the windows_hide argument (Python >= 3.7) or the creationflags argument (Python < 3.7).
win_kwargs = {}
if sys.platform == "win32":
    win_kwargs["creationflags"] = subprocess.CREATE_NO_WINDOW

result = subprocess.run(["g++", str(source.absolute()), "-o", executable, *compile_options], check=False, capture_output=True, text=True, **win_kwargs)

# If compilation fails, print the error message to the console. Otherwise, run the compiled executable and print its output.
if result.returncode != 0:
    stderr_output = result.stderr.replace(str(source.absolute()), str(source.name)) # strip absolute path from error message to make it more readable
    print(stderr_output, end="")
else:
    result = subprocess.run([executable], check=False, capture_output=True, text=True, **win_kwargs)
    print(result.stdout, end="")