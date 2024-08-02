# Score.Log

A super simple library to simplify logging for applications

More information is in the [Motivation and Goals](#motivation-and-goals)
section below.

## Features
- Levelled logging
- Multiple output sinks
- 'Virtual Namespacing' of main library functions

## Installing
> This section is currently still a work in progress

#### Requirements
- `tar`
- `gcc`/`clang` (or any other C99 or later compatible C compiler)
- `make`

#### Compiling

The GNU Autotools setup allows for a quick and easy installation from
source distributions. After making sure you have all the dependencies
and have downloaded the source tarball, compilation should be as simple
as running the following commands:

```shell
$ tar -xaf score_log-*.tar.xz
$ cd score_log-*/
$ ./configure
$ make
```
#### Testing
Testing in this project is provided by
[Criterion](https://github.com/Snaipe/Criterion) and is integrated into
the autotools build configuration. As a result running all the unit
tests is as simple as running a single command after configuring the
project:
```shell
$ make check
```

#### Installing
Installing system-wide will require superuser privileges:

```shell
$ sudo make install
```

## Usage


## Motivation and Goals
The primary motivation of this project is to work as a less trivial
example project for other open source projects to use as a reference
in multiple areas:
- Readme writing
- Autotools example usage
- Automated testing

Additionally, this project serves as a demonstration of pre-decided
preferences:
- C code formatting
- Project layout
- Standards usage

## Authors
- [ecerulm](https://github.com/ecerulm) - Project template
- [Melephas](https://github.com/Melephas) - All the rest

## Acknowledgements
* A big thank you to `ecerulm` for the `autotools-template`
  repository

## Links
- [autotools-template](https://github.com/ecerulm/autotools-template)
  repository
