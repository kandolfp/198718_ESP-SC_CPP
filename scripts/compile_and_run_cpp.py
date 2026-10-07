"""
Script to compile and run a C++ file (or multiple files).
The output from stdout is printed to the console --> shown like normal Quarto output.
The result object is available for further processing, e.g. to extract data, etc.

If multiple translation units are provided, they must be passed before any compiler options and will be compiled together into a single executable.
The resulting executable will have the same name as the first source file.
"""

import subprocess
import sys
from pathlib import Path

# parse all arguments into source files and compiler options
arguments = sys.argv[1:]
source_paths = []
compile_options = []

# assumes all src files come first, then compiler options --> makes parsing more convenient
found_compiler_option = False
for arg in arguments:
    if arg.startswith("-"):
        found_compiler_option = True

    if found_compiler_option:
        compile_options.append(arg)
    else:
        source_paths.append(arg)

# By default optimized with -O3, but for some examples we need to disable optimization
if not any(opt.startswith("-O") for opt in compile_options):
    compile_options.insert(0, "-O3")

sources: list[Path] = [(Path.cwd() / path).resolve() for path in source_paths]
executable = str(sources[0].absolute().with_suffix(""))

# By default subprocess.run() will open a new console window on Windows, which captures focus and is quite annoying.
# This is surpressed using either the windows_hide argument (Python >= 3.7) or the creationflags argument (Python < 3.7).
win_kwargs = {}
if sys.platform == "win32":
    win_kwargs["creationflags"] = subprocess.CREATE_NO_WINDOW

result = subprocess.run(["g++", *map(str, sources), "-o", executable, *compile_options, "-fdiagnostics-color=always"], check=False, capture_output=True, text=True, **win_kwargs)

# If compilation fails, print the error message to the console. Otherwise, run the compiled executable and print its output.
if result.returncode != 0:
    for src in sources:
        stderr_output = result.stderr.replace(str(src.absolute()), str(src.name)) # strip absolute path from error message to make it more readable

    print(stderr_output, end="")
else:
    result = subprocess.run([executable], check=False, capture_output=True, text=True, **win_kwargs)
    print(result.stdout, end="")