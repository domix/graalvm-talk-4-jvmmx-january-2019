# Examples to running multiple languages with GraalVM

## Ruby

Running with typical Ruby installation:


Running with GraalVM:

```
$JAVA_HOME/jre/languages/ruby/bin/ruby factorial.rb 20
Engine:   truffleruby, Platform: x86_64-darwin, Version:  2.4.4
2432902008176640000
$JAVA_HOME/jre/languages/ruby/bin/ruby factorial.rb 20  0.06s user 0.12s system 40% cpu 0.440 total
```