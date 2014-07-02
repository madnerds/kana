<?php
//Logout
if(isset($_["logout"]) && !isset($_["submit"])){
//Delete Cookie if it exist
	if(isset($_COOKIE[COOKIE_NAME])){
		$user = new Entity("Users");
		$user = $user->load(array("id"=>$currentUser->Id()));
	$user->setCookie(""); //Reset cookie token
	$user->save();
	Functions::destroyCookie(COOKIE_NAME);
}
$_SESSION = array();
session_unset();
session_destroy();
$currentUser = new User();
redirect("index");
}

/*Submit form*/
	if(isset($_["submit"])){
			//Check user
		$currentUser = new User();
		$cookie = isset($_["cookie"]);
		$currentUser->check_password($_["username"],$_["pass"],$cookie);

		//User OK
		if($currentUser->isuser()){
			$_SESSION['currentUser'] = serialize($currentUser);
			redirect("display","?notice=".t("You are logged"));
		}
		else{
		//User Not OK
			redirect("index","?error=".t("This account doesn't exist"));
		}
	}

?>