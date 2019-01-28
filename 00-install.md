


# Default and old installation way....

https://www.graalvm.org/docs/getting-started/#install-graalvm

# Installation with SDKManager

My personal and preferred way to install any `Java` distribution and `GraalVM` is with `SDKManager`.

## Install SDK

https://sdkman.io/install

```
$ curl -s "https://get.sdkman.io" | bash
```

## Verify which Java distribution we have installed with SDK

```
$ sdk list java
================================================================================
Available Java Versions
================================================================================
     13.ea.02-open       8.0.191-oracle
     12.ea.26-open       8.0.181-oracle
     11.0.2-zulu         7.0.181-zulu
     11.0.2-open         1.0.0-rc9-graal
     11.0.1-open         1.0.0-rc8-graal
     11.0.1-zulufx       1.0.0-rc7-graal
     10.0.2-zulu         1.0.0-rc6-graal
     10.0.2-open         1.0.0-rc-11-grl
     9.0.7-zulu          1.0.0-rc-10-grl
     9.0.4-open          1.0.0-rc-9-grl
     8.0.202-amzn        1.0.0-rc-8-grl
     8.0.201-zulu
     8.0.201-oracle
     8.0.192-amzn
     8.0.192-zulufx

================================================================================
+ - local version
* - installed
> - currently in use
================================================================================
```

## Installing the most recent `GraalVM` version.

```
$ sdk install java 1.0.0-rc-11-grl
```

Please wait until installation ends...

Then we can verify the installation:

```
$ sdk list java
================================================================================
Available Java Versions
================================================================================
     13.ea.02-open       8.0.191-oracle
     12.ea.26-open       8.0.181-oracle
     11.0.2-zulu         7.0.181-zulu
     11.0.2-open         1.0.0-rc9-graal
     11.0.1-open         1.0.0-rc8-graal
     11.0.1-zulufx       1.0.0-rc7-graal
     10.0.2-zulu         1.0.0-rc6-graal
     10.0.2-open     > * 1.0.0-rc-11-grl
     9.0.7-zulu          1.0.0-rc-10-grl
     9.0.4-open          1.0.0-rc-9-grl
     8.0.202-amzn        1.0.0-rc-8-grl
     8.0.201-zulu
     8.0.201-oracle
     8.0.192-amzn
     8.0.192-zulufx

================================================================================
+ - local version
* - installed
> - currently in use
================================================================================
```

## Running GraalVM

```
$ java -version
openjdk version "1.8.0_192"
OpenJDK Runtime Environment (build 1.8.0_192-20181024123616.buildslave.jdk8u-src-tar--b12)
GraalVM 1.0.0-rc11 (build 25.192-b12-jvmci-0.53, mixed mode)
```

