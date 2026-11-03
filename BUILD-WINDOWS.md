# Eclipse Menu — GD 2.2091 / Geode 6.0.0-alpha.1 (Windows)

Port status: NOT compiled yet (no Windows toolchain was available when this was prepared).
Build with GitHub Actions: Actions -> "Build Eclipse (Windows, ...)" -> Run workflow.
Artifact `eclipse-windows` contains `eclipse.eclipse-menu.geode`.

Changes made vs. v1.9.4:
- mod.json: geode 6.0.0-alpha.1, gd 2.2091
- gd::string -> std::string (8 files); removed unused geode::Task alias
- Geode 6 paths are asp::fs::Path: added src/fs_compat.hpp (toStd/toAsp/toString + matjson
  serializer for std::filesystem::path) and used it at every Geode file/dir API call
- pathToString (removed in Geode 6) -> eclipse::fsx::toString
- file picker callbacks use geode::utils::file::PickResult
- old multi-platform/publish workflows removed, Windows-only workflow added

If the build fails, send the log of the failing step.
