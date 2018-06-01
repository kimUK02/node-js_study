var log = console.log.bind(this);

var d1 = 2/0;
var d2 = -2/0;
//log("d1 = "+ d1);
//log("d2 = "+ d2);

var weak1 = 100/"apple";
var weak2 = 100/"100";
//log("weak1 = "+ weak1);
//log("weak2 = "+ weak2);

var nan1 = 5 + NaN;
//log("nan1 = "+ nan1);
//log("Typeof NAN = " + typeof NaN);

var prim = 500;
var obj = new Number(500);
var obj2 = new Number(500);
var obj3 = new Number();

// log("prim = " + prim);
// log("obj = " + obj);
// log("obj3 = " + obj3);

// log("Typeof Prim = "+ typeof prim);
// log("Typeof obj = "+ typeof obj);

// log("prim == obj  "+ (prim==obj));
// log("prim === obj  "+ (prim===obj));
// log("obj == obj2 "+ (obj == obj2))

var strnum = "600";
// log("typeof Number(strnum) = "+ typeof Number(strnum));
// log("typeof strnum = "+ typeof(strnum));

log([]+[] === "");
{}+[];
log(+[]===0);
log([0]==[0])