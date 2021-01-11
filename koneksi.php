<?php
$dbhost = 'localhost';
$dbuser = 'root';
$pass = '';
$dbname = 'control_led';

$conn = new mysqli($dbhost, $dbuser, $pass, $dbname);

if ($conn->connect_error) {
    die('Server Bermasalah');
}
