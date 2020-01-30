<?php # Script 12.11 - logout.php #2
// This page lets the user logout.
// This version uses sessions.
session_start(); // Access the existing session.
echo"<br/><br/>";
// If no session variable exists, redirect the user:
if (!isset($_SESSION['user_id'])) {
	// Need the functions:
	require('login_functions1.php');
	redirect_user();
} else { // Cancel the session:
	$_SESSION = []; // Clear the variables.
	session_destroy(); // Destroy the session itself.
	setcookie('PHPSESSID', '', time()-3600, '/', '', 0, 0); // Destroy the cookie.
}
// Set the page title and include the HTML header:
$page_title = 'Logged Out!';
require('header.html');
// Print a customized message:
echo "<h1>Logged Out!</h1>
<p>You are now logged out!</p>";

?>