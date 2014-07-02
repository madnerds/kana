<?php
/*
Display footer (javascript include and notifications)
*/


//Manage Error Message
if(isset($_["error"])){
	$error = t($_["error"]);
}
else
{
	$error = false;
}

if(isset($_["notice"])){
	$notice = t($_["notice"]);
}
else
{
	$notice = false;
}

$tpl->assign("js",$theme->js()); //Theme JS
$tpl->assign("error_message",$error); //ERROR MESSAGE (javascript)
$tpl->assign("notice_message",$notice); //NOTICE MESSAGE (javascript)
$tpl->draw(CORE_TEMPLATE."footer"); //load core/templates/footer.html
?>
