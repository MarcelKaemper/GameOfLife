console.log("Test");

let size = 100;

let array = "static int game["+size*size+"] = {";

for(let i = 1; i<=size*size; i++){
		array += "0";
		if(i % 100 == 0){
			array += "\n";
		}
		if(i<size*size){
			array += ",";
		}
}

array += "};";

console.log(array);
