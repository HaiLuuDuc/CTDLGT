character:
EatBrick()
- groundBrick.setActive(false)
- instantiate(brickPrefab) in balo, rigidbody=false, boxCollider=false
- baloBrick.rigid=false, 
- baloBrick.boxCollider=false
//- balobrick.position=balobricklast.position + balobrickHeight;

DropBrick()
- balo.ReturnObject(balobrick);
- for(list){
	GameObject obj = list[i];
	if(!obj.activeSelf){
		obj.setActive(true);
		obj.color = color of character dropping brick;
		break;
	}
}

=============================================================================================================


// build initial list
list<vector3> groundBrickPositionList
list<GameObject> groundBrickObjectList
list<bool> groundBrickStatusList
list<GameObject> baloBrickObjectList;
enum MaterialType {
    Blue, Green, Red
};
Material[] materialArray = new Material[3]; // blue, green, red
//initial list of ground bricks
for (int i = 0; i < brickTile.transform.childCount; i++)
    {       
        GameObject brick = brickTile.transform.GetChild(i).gameObject;
        brick.gameObject.GetComponent<MeshRenderer>().material = materials[Random.Range(0,3)];
        groundBrickObjectList.Add(brick);
		groundBrickStatusList.Add(true);
		groundBrickPositionList.Add(brick.transform.position);  
		brick.setActive(false);      
    }


// character functions
EatBrick(GameObject brick){	
	ChangeColor(brick,this.material)
	int index = brickObjectList.FindIndexOf(collider.gameObject);
	groundBrickStatusList[index] = false;
	brick.transform.SetParent(balo);
	brick.transform.localPosition = baloBrickObjectList[last].localPosition + brickHeight;
	baloBrickObjectList.Add(brick);
}
DropBrick(){
	for(int i=0;i<groundBrickObjectList.Count;i++){
		if(groundBrickStatusList[i]==false){
			groundBrickStatusList[i] = true;
			lastbrick.transform.SetParent(null);
			lastbrick.transform.position = groundBrickPositionList[i];
			baloBrickObjectList.Remove(last brick);
		}
	}
}
Fall(){
	- tat ca brick trong balo se roi ra ngoai va co collider. //GetComponentsInChildren 
	BoxCollider[] colliders = balo.GetComponentsInChildren<BoxCollider>();
	for(baloList){
		baloList[i].material = grey;
		baloList[i].setparent(null);
		colliders[i].isTrigger = false;
	}
}
//brick chi co collider khi roi xuong dat
//so sanh material dung referenceEqual(mat1,mat2)
ChangeColor(GameObject obj, Material newMaterial){ // truong hop an cac brick mau xam
	if(obj.Material !=  newMaterial){ 
		obj.Material =  newMaterial;
	}
}

// bricks appear only when character enter stage
onStageColiision(){
	if(colision is character){
		for(int i=0;i<listCount;i++){
			if(list[i].material==character.material){
				list[i].setActive(true);
				destroy this script;
			}
		}
	}
}




