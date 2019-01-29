# cpdry
hmmm

# TODO

* magic #includes (autodetect which std header lib a term is from), manual #includes (terms not included unless manually specified)
* default to NOT exporting symbols (i.e. use static or anonymous namespaces) unless explicitly stated otherwise
* auto namespace fixing syntax (sugar)
* loop magic, e.g. add an enumerate variable
* ability to upgrade a variable to const halfway through a block
* syntactic try/finally (not exception-safe) ; do this by banning abort(), exit(), return, etc. inside nested blocks
* if/else to initialize const variables without explicit lambda
