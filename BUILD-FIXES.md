# Eclipse — build correction based on the latest GitHub Actions log

Target: Windows x64, Geometry Dash 2.2091, Geode 6.0.0-alpha.1.

## Fixes made

1. Changed `gd-imgui-cocos` to download the exact upstream `prevter` commit as a source archive, avoiding the previous CPM Git-tree checkout failure.\n2. Disabled CMake Unity Build on GitHub Actions. The log showed `AdvancedLabel.cpp`
   compiled inside a unity translation unit and a name collision between the
   global `Label` class and `geode::Label`.
3. Removed the incompatible Globed soft-link header from the labels variable module.
   The log showed Globed 2.2.2 calling the old two-argument `GEODE_EVENT_EXPORT`,
   while Geode 6 defines a four-argument macro. The `globed.enabled` variable remains;
   network stats are initialized to safe zero/false values until the soft-link API
   is updated for Geode 6.
4. Kept the pinned bindings revision that had already passed Codegen.
5. The workflow uploads only the `.geode` package and fails if it was not produced.

## Important

This addresses the exact compiler errors in the supplied log. A successful
Windows Actions build and an in-game test have not yet been run, so this is
not a guaranteed final release. If the next run reports a new compiler error,
that will be the next issue to fix.


## Correctifs V3 (journal du 2 novembre 2026)
- `Bot.cpp`: adapte le hook `PlayLayer::init` à la signature Geode 6 (`GJGameLevel*, bool`).
- `MemoryPracticeFix.cpp`: remplace la borne inexistante `m_ringRelatedSet` par le champ existant `m_objectSnappedTo` pour conserver la surveillance de cette plage mémoire.
