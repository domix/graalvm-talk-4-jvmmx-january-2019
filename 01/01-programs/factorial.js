function rFact(num)
{
    if (num === 0)
      { return 1; }
    else
      { return num * rFact( num - 1 ); }
}
console.log("Version: ", process.version)
//console.log(process.versions)
console.log("V8:      ",process.versions.v8)

//console.log(process)
var program_name = process.argv[2];

console.log(rFact(program_name));
