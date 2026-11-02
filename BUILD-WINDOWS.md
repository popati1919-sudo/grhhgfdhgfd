# Eclipse Menu — Windows build

Target: Geometry Dash 2.2091 / Geode 6.0.0-alpha.1 / Windows x64.

## Build

1. Push this project to your GitHub repository.
2. Open **Actions**.
3. Select **Build Eclipse (Windows, GD 2.2091, Geode 6.0.0-alpha.1)**.
4. Select **Run workflow**.
5. When the job succeeds, open its run and download the `eclipse-windows-gd-2.2091` artifact.

## Build fixes in this package

- Geode bindings are pinned to `6d07d9afba68cf7f69cc37f360c4ffe35b1c0cc2`, the revision used after the Broma parsing failure.
- `gd-imgui-cocos` is fetched from the original `prevter/gd-imgui-cocos` repository at commit `e66d02bef18f15105500b914a12f2a2d9bb59f21` as a source archive. This avoids the failed CPM Git tree checkout.
- The CPM cache is disabled for this workflow so a previously cached broken checkout is not reused.
- Artifact upload fails clearly if no `.geode` package was produced.

## Validation status

The source archive and workflow configuration have been checked. A successful Windows compilation and in-game runtime test still need to be confirmed by running the GitHub Actions workflow; this environment does not provide the Windows Geode toolchain.
