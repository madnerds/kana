<?php
if(DEBUG){
	debug("PHP","Variables");
	var_dump($_);
}

//Save Configuration
$config_language = $_["lang"];
$config_theme = "bootstrap";
$config = new Entity("Config");
$config->create();
$config->setLanguage($config_language);
$config->setTheme($config_theme);
$config->save();

//Save First User
$name = $_["admin_name"];
$password = $_["admin_pass"];
$user_db = new Entity("Users");
$user_db->create();
$user_db->setName($name);
$user_db->setLastName("");
$user_db->setFirstName("");
$user_db->setEmail("");
$user_db->setState("1");
$user_db->setCookie("");
$user_db->setToken("");
$user_db->setPassword(sha1(md5($password)));
$user_db->save();

unset($_SESSION);
//Redirect to index
redirect("index","?notice=".t("Installation successful"));
?>