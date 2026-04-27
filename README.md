# OSTEP-projects

My solutions for projects inside OSTEP (Operating System Three Easy Pieces) book.
The solutions are tuned to pass the OSTEP book tests.

## Initial-Utilities

Specification: build simple clone of unix utility tools (cat, grep, zip, unzip) with handling any possible errors and enabling multi-file feature <br>
- cat: read and combine file contents
- grep:
- zip:
- unzip:

Note: the '>' (Output Redirection) feature is not included in the solution, because the author of the book said that we will gonna take it in the future chapters, so the output is always in the stdout (standard output)

## Compilation

To compile any program use: `gcc program-name.c -o output-file-name -Wall -Werror`, then simply run it using `./output-file-name`. <br>

The `-Wall` flag enables all common compiler warnings, and the `-Werror` flag treat all warnings as errors.
