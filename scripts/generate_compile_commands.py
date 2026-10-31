"""Generate editor compile commands from the flags supplied by Make."""

import argparse
import json
from pathlib import Path
import shlex

parser = argparse.ArgumentParser()
parser.add_argument("--cxx", required=True)
parser.add_argument("--flags", required=True)
args = parser.parse_args()

root = Path(__file__).resolve().parent.parent
entries = []
for source in sorted((root / "src").rglob("*")):
    if source.suffix not in {".cpp", ".mm"}:
        continue
    relative = source.relative_to(root)
    output = Path("build") / relative.with_suffix(".o")
    entries.append({
        "directory": str(root),
        "file": str(source),
        "arguments": shlex.split(args.cxx) + shlex.split(args.flags)
        + ["-c", str(relative), "-o", str(output)],
    })

destination = root / "build" / "compile_commands.json"
destination.parent.mkdir(parents=True, exist_ok=True)
destination.write_text(json.dumps(entries, indent=2) + "\n")
