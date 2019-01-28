# GraalVM talk

## What is GraalVM?

> GraalVM is a universal virtual machine for running applications written in JavaScript, Python, Ruby, R, JVM-based languages like Java, Scala, Kotlin, Clojure, and LLVM-based languages such as C and C++.
>
> GraalVM removes the isolation between programming languages and enables interoperability in a shared runtime. It can run either standalone or in the context of OpenJDK, Node.js, Oracle Database, or MySQL.
>
> [GraalVM website](https://www.graalvm.org/)

## Usage

You can use GraalVM as replacement of your `JDK` and `JRE` if you want. You will not notice any difference at all.

[GraalVM installation](00-install.md)

## Features

* GraalVM is based in OpenJDK 1.8.0
* So far, you can run any JVM based language with GraalVM, also JavaScript.
* For Ruby and R the team is working on improved completeness.
* LLVM-based languages is supported
* Python support is just beginning.
* GraalVM can run embedded in a Java VM, stand-alone, or embedded in data stores like the Oracle RDBMS and MySQL
* There is a community edition (CE) and an enterprise edition (EE) of GraalVM. The community edition is distributed under an open source license. It is free to use in production and comes with no strings attached, but also no guarantees or support. The enterprise edition is available from the Oracle Technology Network under an evaluation license.