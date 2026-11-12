# bd stops looking for its database at a git repo boundary, and mise sets
# BEADS_DIR only under ~/workbench.
export-env {
    $env.BEADS_DIR = $nu.home-dir | path join workbench .beads
}
