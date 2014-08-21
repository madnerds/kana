//Plugin Ajax Download / install/  uninstall / update

function getplugins(button,repo){
searchterms = $("#searchterms").val().trim();
$("#plugin_list").html("");

if(searchterms == ""){
	searchterms = "all";
	console.log("ALL PLUGINS");
}

data_link = "remoteplugins";
data_id = "plugins";
	//AJAX	
		$.ajax({
			url: "actions.php",
			dataType: "json",
			data: {type: "data", data: data_link , data_id: data_id,searchterms : searchterms}
		}).done(function ( data ) {
			console.log("Plugin list acquire");
			for (var i = data.length - 1; i >= 0; i--) {
				plugin_repo = data[i]["repo"];
				plugin_name = data[i]["name"];
				plugin_type = data[i]["type"];
				getplugininfo(plugin_repo,plugin_name,plugin_type);
			};
		});
}

function getplugininfo(plugin_repo,plugin_name,plugin_type){
data_link = "remoteplugininfo";
data_id = "plugins";
	//AJAX	
		$.ajax({
			url: "actions.php",
			data: {type: "data", data: data_link , data_id: data_id, plugin_repo: plugin_repo, plugin_name: plugin_name,plugin_type: plugin_type}
		}).done(function ( data ) {
			console.log("Plugin info get "+plugin_repo+" "+plugin_name);
			$("#plugin_list").append(data);
		});
}

function installplugin(button,plugin_repo,plugin_name,plugin_type){
	console.log("Install plugin: "+plugin_repo + plugin_name + plugin_type)
	$.ajax({
			url: "actions.php",
			data: {type: "installplugin", plugin_repo: plugin_repo, plugin_name: plugin_name, plugin_type: plugin_type}
		}).done(function ( data ) {
			console.log("Downloading plugin"+plugin_repo+" "+plugin_name);
			console.log(data);
		});
}

function uninstallplugin(button,plugin_name,plugin_type){
	console.log("Install plugin: "+plugin_repo + plugin_name + plugin_type)
	$.ajax({
			url: "actions.php",
			data: {type: "uninstallplugin", plugin_repo: plugin_repo, plugin_name: plugin_name, plugin_type: plugin_type}
		}).done(function ( data ) {
			console.log("Downloading plugin"+plugin_repo+" "+plugin_name);
			console.log(data);
		});
} 