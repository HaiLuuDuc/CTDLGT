Player.cs
public WeaponType currentWeaponType;
public Weapon currentWeapon;
public void ChangeWeapon(WeaponType weaponType){
	this.currentWeaponType = weaponType;
	this.currentWeapon = Weapons.instance.GetWeapon(weaponType);
}


WeaponData.cs
public enum WeaponType
{
	Knife, Hammer, Boomerang	
}
WeaponData:ScriptableObject
public WeaponType weaponType;
public Sprite icon;
public enum MaterialType;
public Material[] weaponMaterials;
public Material GetWeaponMaterial(MaterialType materialType){
	return weaponMaterials[(int)materialType];
}




