<?php
//http://163.238.35.165/~lattanzio/Sep16.html
?>
<html>
<body>
<h1> Hello </h1>

<?php

$users = array("joeDoe"=>"goProgramPHP!","junk0"=>"isthismypassword","busyBee"=>"pass20word","computerGal"=>"pass30word","compGuy"=>"mypass2309","expertComp"=>"60your78","smartone"=>"78y68pal","johndoe"=>"pass4567","johndoe3"=>"pass2100","johndoe67"=>"pass2099");

foreach($users as $k => $v){
	if(($_POST['x']==$k) && ($_POST['y'] == $v)){
		$check = true;
		break;
	}
	else {
		$check = false;
		
	}
}

	if($check == true)
		echo "Welcome $k, You have successfully logged in.";
	else if ($check == false)	
		echo" Wrong sign in infromation, try again.";


?>
</body>
</html>