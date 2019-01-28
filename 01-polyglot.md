# Truffle

[Truffle] is a framework for implementing languages using nothing more than a simple abstract syntax tree interpreter.

Also is a framework for writing interpreters with annotations and small bits of extra code that will be converted into `JIT` compiling `VMs` automatically. The resulting runtimes have peak performance competitive with the best hand-tuned language-specific compilers on the market. For example, the `TruffleJS` engine which implements `JavaScript` is competitive with `V8` in benchmarks. The `RubyTruffle` engine is faster than all other `Ruby` implementations by far.

`Truffle` provides a language interop framework called `Polyglot` that allows `Truffle` languages to call each other, and a thing called the `Truffle Object Storage Model` that standardises and optimises much of the behaviour of dynamically typed objects, allowing languages to share them too. And because `Graal` & `Truffle` are fundamentally built on top of the `JVM`, all these languages can also call in and out of `JVM` bytecode-based languages like `Java`, `Scala` and `Kotlin` too.

The way `Polyglot` works is unusual. Because `Truffle` provides a standard framework for expressing nodes in an abstract syntax tree, calling into another language doesn’t involve any complex hand-written binding layers. Instead, invoking a function simply joins the `ASTs` of the two languages together. Those two `ASTs` are then compiled and optimised by `Graal` as a single unit, meaning any complexity introduced by crossing the language barrier can be analysed and eliminated.

It’s for this reason that researchers decided to implement a C interpreter on top of Truffle. We normally think of C as being an inherently compiled language, but there’s no particular reason it must be so, and in fact C interpreters have a long history of usage.

Because scripting languages are so slow it’s very common to rewrite performance hotspots in dynamically typed programs by hand in C, using the original interpreter’s internal API to interact with the scripted code. Perversely, this technique actually makes it harder to speed up the language in general because running real programs often means running their C extensions too, and that’s very difficult when those extensions make so many assumptions about the runtime’s internals.

When the people creating RubyTruffle hit this problem they came up with a clever solution: write a special C source code interpreter that not only understands ordinary C, but also macros and other constructs that are unique to Ruby extensions. Then by merging the Ruby and C interpreters together on top of the Truffle framework, the code will be blended together into a seamless whole and the interop overhead will be optimised away. This interpreter is called TruffleC.

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
$JAVA_HOME/jre/languages/ruby/bin/ruby factorial.rb 20  0.06s user 0.12s system 40% cpu 0.440 total
```