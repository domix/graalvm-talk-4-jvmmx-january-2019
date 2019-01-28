# Truffle

Truffle is a framework for implementing languages using nothing more than a simple abstract syntax tree interpreter.

Truffle is a framework for writing interpreters with annotations and small bits of extra code in them which, when Truffle is paired with its sister project Graal, allow those interpreters to be converted into JIT compiling VMs … automatically. The resulting runtimes have peak performance competitive with the best hand-tuned language-specific compilers on the market. For example, the TruffleJS engine which implements JavaScript is competitive with V8 in benchmarks. The RubyTruffle engine is faster than all other Ruby implementations by far.


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