<html>
<head><title>Form and Processing</title></head>
<body>
<?php
//When first running page says there is error on line 28 but still runs correctly.
function putForm($users)
{
echo "<form action='oneFile.php' method='post'>Enter Your Username:
	<input type='text' name='x'/>
		<br />";
 echo "Enter Your Password : <input type='password' name='y'/>

		<br />";

 echo "<br />

		<input type='submit' name = 'submit' value='Login' />
		<br />

		";
}
?>
 <h1> Hello </h1>

<?php

$users = array("joeDoe"=>"goProgramPHP!","junk0"=>"isthismypassword","busyBee"=>"pass20word","computerGal"=>"pass30word","compGuy"=>"mypass2309","expertComp"=>"60your78","smartone"=>"78y68pal","johndoe"=>"pass4567","johndoe3"=>"pass2100","johndoe67"=>"pass2099");
putForm($users);

$name = $_POST['x'];
$password = $_POST['y'];
if($name && $password){
	foreach($users as $k => $v){
		if(($name==$k) && ($password == $v)){
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
}else{
	echo "Please sign in.";
}





?>
 </body>
 </html>
