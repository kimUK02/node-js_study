<?php
session_start();
$username = $_POST['username'];
$password = $_POST['password'];

$sql = "SELECT * FROM users WHERE username={$username}";

echo $sql;

$mysql = new mysqli('127.0.0.1', 'root', 'so621313', 'php_test');

$result = $mysql->query($sql);

if ($result) {
    echo 'success database';
} else {
    echo 'failed';
}

$user = $result->fetch_object(User::class);

if ($user->verifyPassword($password)) {
    echo 'success';
    $_SESSION['user'] = $user;
    //TODO: do when successfully logged in
} else {
    echo 'failure';
    //TODO: do when failed logged in
}