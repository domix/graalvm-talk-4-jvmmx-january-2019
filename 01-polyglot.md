# Truffle

`Truffle` is a framework for implementing languages using nothing more than a simple abstract syntax tree interpreter.

Also is a framework for writing interpreters with annotations and small bits of extra code that will be converted into `JIT` compiling `VMs` automatically. The resulting runtimes have peak performance competitive with the best hand-tuned language-specific compilers on the market. For example, the `TruffleJS` engine which implements `JavaScript` is competitive with `V8` in benchmarks. The `RubyTruffle` engine is faster than all other `Ruby` implementations by far.

`Truffle` provides a language interop framework called `Polyglot` that allows `Truffle` languages to call each other, and a thing called the `Truffle Object Storage Model` that standardises and optimises much of the behaviour of dynamically typed objects, allowing languages to share them too. And because `Graal` & `Truffle` are fundamentally built on top of the `JVM`, all these languages can also call in and out of `JVM` bytecode-based languages like `Java`, `Scala` and `Kotlin` too.

The way `Polyglot` works is unusual. Because `Truffle` provides a standard framework for expressing nodes in an abstract syntax tree, calling into another language doesn’t involve any complex hand-written binding layers. Instead, invoking a function simply joins the `ASTs` of the two languages together. Those two `ASTs` are then compiled and optimised by `Graal` as a single unit, meaning any complexity introduced by crossing the language barrier can be analysed and eliminated.

It’s for this reason that researchers decided to implement a `C` interpreter on top of `Truffle`. We normally think of `C` as being an inherently compiled language, but there’s no particular reason it must be so.

Because scripting languages are so slow it’s very common to rewrite performance hotspots in dynamically typed programs by hand in `C`, using the original interpreter’s internal `API` to interact with the scripted code. Perversely, this technique actually makes it harder to speed up the language in general because running real programs often means running their `C` extensions too, and that’s very difficult when those extensions make so many assumptions about the runtime’s internals.

When the people creating `RubyTruffle` hit this problem they came up with a clever solution: write a special `C` source code interpreter that not only understands ordinary `C`, but also macros and other constructs that are unique to `Ruby` extensions. Then by merging the `Ruby` and `C` interpreters together on top of the `Truffle` framework, the code will be blended together into a seamless whole and the interop overhead will be optimised away. This interpreter is called `TruffleC`.

Resources to review:

* [Very High Performance C Extensions For JRuby+Truffle](https://chrisseaton.com/truffleruby/cext/)

* [Paper: PDF. High-Performance Cross-Language
Interoperability in a Multi-language Runtime](https://chrisseaton.com/rubytruffle/dls15-interop/dls15-interop.pdf)


# Examples to running multiple languages with GraalVM

## Ruby

In order to run Ruby programs we should install the GraalVM binary using the `gu` program:

```
$ gu install ruby
Downloading: Component catalog
Processing component archive: Component ruby
Downloading: Component ruby
Installing new component: TruffleRuby (org.graalvm.ruby, version 1.0.0-rc11)

IMPORTANT NOTE:
---------------
The Ruby openssl C extension needs to be recompiled on your system to work with the installed libssl.
First, make sure TruffleRuby's dependencies are installed, which are described at:
  https://github.com/oracle/truffleruby/blob/master/README.md#dependencies
Then run the following command:
        $JAVA_HOME/jre/languages/ruby/lib/truffle/post_install_hook.sh


IMPORTANT NOTE:
---------------
Set of Graal VM components that provide language implementations have changed. 
The Polyglot native image and polyglot native C library may be out of sync:
- new languages may not be accessible
- removed languages may cause the native binary to fail on missing resources or libraries.
To rebuild and refresh the native binaries, use the following command:
        $JAVA_HOME/jre/bin/gu rebuild-images
```

Running with typical Ruby installation:

```
$ /usr/bin/ruby 01-programs/factorial.rb 20
Engine:   ruby, Platform: universal.x86_64-darwin18, Version:  2.3.7
2432902008176640000
```

Running with GraalVM:

```
$ $JAVA_HOME/jre/languages/ruby/bin/ruby 01-programs/factorial.rb 20
Engine:   truffleruby, Platform: x86_64-darwin, Version:  2.4.4
2432902008176640000
```
## Python

In order to run Python programs we should install the GraalVM binary using the `gu` program:

```
$ gu install python
Downloading: Component catalog
Processing component archive: Component python
Downloading: Component python
Installing new component: Graal.Python (org.graalvm.python, version 1.0.0-rc11)

IMPORTANT NOTE:
---------------
Set of Graal VM components that provide language implementations have changed. 
The Polyglot native image and polyglot native C library may be out of sync:
- new languages may not be accessible
- removed languages may cause the native binary to fail on missing resources or libraries.
To rebuild and refresh the native binaries, use the following command:
        $JAVA_HOME/jre/bin/gu rebuild-images
```

Running with typical Python installation:

```
$ /usr/bin/python 01-programs/factorial.py 20
sys.version_info(major=2, minor=7, micro=10, releaselevel='final', serial=0)
2432902008176640000
```

Running with GraalVM:

```
$ $JAVA_HOME/jre/languages/python/bin/graalpython 01-programs/factorial.py 20
Please note: This Python implementation is in the very early stages, 
and can run little more than basic benchmarks at this point.
version_info(major=3, minor=7, micro=0, releaselevel='dev', serial=0)
2432902008176640000
```



## JavaScript

JavaScript support will work out of the box


Running with typical NodeJS installation:

```
$ /usr/local/bin/node 01-programs/factorial.js 20
Version:  v11.7.0
V8:       7.0.276.38-node.16
2432902008176640000
```

Running with GraalVM:

```
$ $JAVA_HOME/jre/languages/js/bin/node 01-programs/factorial.js 20
Version:  v10.9.0
V8:       6.7.0.0-node.0
2432902008176640000
```

## R

In order to run `R` programs we should install the `GraalVM` binary using the `gu` program:

```
$ gu install r
Downloading: Component catalog
Processing component archive: Component r
Downloading: Component r
Installing new component: FastR (org.graalvm.R, version 1.0.0-rc11)
NOTES:
---------------
Some R packages need a system-dependent configuration before they can be 
installed. A generic configuration that works out of the box in most cases is 
provided by default. If you wish to fine-tune the configuration to your system 
or should you encounter any issues during R package installation, try running 
the following script that adjusts the configuration to your system:
    $JAVA_HOME/jre/languages/R/bin/configure_fastr

The R component comes without native image by default. If you wish to build 
the native image, which provides faster startup, but slightly slower peak 
performance, then run the following:
   $JAVA_HOME/jre/languages/R/bin/install_r_native_image

The native image is then used by default. Pass '--jvm' flag to the R or 
Rscript launcher to use JVM instead of the native image. Note that the native 
image is not stable yet and is intended for evaluation purposes and 
experiments. Some features may not work when the native image is installed, 
most notably the --polyglot switch. The native image can be uninstalled using 
the installation script with 'uninstall' argument.

See http://www.graalvm.org/docs/reference-manual/languages/r for more.
```

Running with typical R installation:

```
$ /usr/local/bin/Rscript 01-programs/factorial.r 20
Durante la inicialización - Warning messages:
1: Setting LC_COLLATE failed, using "C"
2: Setting LC_TIME failed, using "C"
3: Setting LC_MESSAGES failed, using "C"
4: Setting LC_MONETARY failed, using "C"
[1] "R version 3.5.2 (2018-12-20)"
[1] "The factorial of 20 is 2432902008176640000"
```

Running with GraalVM:

```
$ $JAVA_HOME/jre/languages/R/bin/Rscript 01-programs/factorial.r 20
[1] "FastR version 3.5.1 (2018-07-02)"
[1] "The factorial of 20 is 2432902008176640256"
```