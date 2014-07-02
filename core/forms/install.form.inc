<?php
$theme = new Theme(INSTALL_THEME);

//Header
include("core/header.inc");

//Menu
$topmenu_selected = [
"text" => "Installation",
"icon" => "glyphicon-asterisk"
];
$topmenu[] = [
"link" => "",
"text" => "Installation",
"icon" => "glyphicon-asterisk"
];
include("core/topmenu.inc");

//Form
include("core/functions/Form.class.php");
$install_form = new Form("Installation");
$install_form->help("Create an admin account");
$install_form->help("Define your language");

$install_form->input([
	"type" => "text",
	"id" => "admin_name",
	"name" => "Login",
	"placeholder" => "admin",
	"selected" => "admin"
	]);

$install_form->input([
	"type" => "password",
	"id" => "admin_pass",
	"name" => "Password",
	]);

$lang_list = get_langlist();
$install_form->input([
	"type" => "select",
	"id" => "lang",
	"name" => "Language",
	"options" => $lang_list,
	"selected" => $_SESSION["LANGUAGE"]
	]);

$install_form->display($tpl);

//Footer
include("core/footer.inc");
//}
?>