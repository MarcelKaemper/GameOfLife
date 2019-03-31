console.log("Test");

let size = 20;

let array = "static int game["+size*size+"] = {";

for(let i = 1; i<=size*size; i++){
		array += "1";
		if(i % 20 == 0){
			array += "\n";
		}
		if(i<size*size){
			array += ",";
		}
}

array += "}";

console.log(array);
