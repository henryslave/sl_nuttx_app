# External

### Selecting External

The external directory contains several sample applications that can be linked
with NuttX. The specific example is selected in the
`boards/<arch-name>/<chip-name>/<board-name>/configs/<config>/defconfig` file
via the `CONFIG_EXTERNAL_xyz` setting where `xyz` is the name of the example.
For example:

```conf
CONFIG_EXTERNAL_appname=y
```

Selects the `external/appname` _appname_ example.

### Built-In Functions

Some of the external may be built as _built-in_ functions that can be executed
at run time (rather than as NuttX _main_ programs). These applications
can be also be executed from the NuttShell (NSH) command line. In order to
configure these built-in NSH functions, you have to set up the following:

- `CONFIG_NSH_BUILTIN_APPS` – Enable support for external registered, _named_
  applications that can be executed from the NSH command line (see
  `apps/README.md` for more information).

## `TBD` Todo: add description

