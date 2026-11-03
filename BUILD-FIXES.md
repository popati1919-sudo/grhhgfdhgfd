# Build fixes for Geometry Dash 2.2091 / Geode 6.0.0-alpha.1

This archive includes compatibility changes for the Windows x64 GitHub Actions build.

- Pins Geode bindings to the known 2.2091-compatible commit used by the workflow.
- Uses the upstream `prevter/gd-imgui-cocos` source archive.
- Disables Unity build for the mod to avoid Geode 6 `Label` name collisions.
- Disables the outdated Globed soft-link calls while keeping stable default values for its data fields.
- Updates the bot code for the Geode 6 `PlayLayer::init` signature and current `PlayerObject` bindings.
- Replaces the unsupported inline `EditorPauseLayer::saveLevel` hook with hooks on the non-inline `onSave`, `onSaveAndExit`, and `onSaveAndPlay` handlers. The level percentage is reset before those save actions.

The ZIP has been structurally checked, but it has not been compiled in a Windows Geode toolchain. Run the GitHub Actions workflow to validate the build.


## V5 - PlayLayer::init Geode 6
- Updated all remaining PlayLayer init hooks to the Geode 6 two-argument signature `init(GJGameLevel*, bool dontCreateObjects)` and updated their base calls accordingly. This addresses the SafeMode.cpp compiler error and prevents the same signature mismatch in other source files.
