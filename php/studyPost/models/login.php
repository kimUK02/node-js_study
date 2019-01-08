<?php
$mysql = new mysqli('localhost','root','so621313','php_test');

if($mysql->connect_errno){
    die('Connect Error: '.$mysql->connect_error);
}

$name = $_POST['input'];
$password = $_POST['password'];
if($_COOKIE['id'])
if(!$name or !$password){ noLogin(); }

$query = "select password from users where username = '$name' ";

if($result = $mysql->query($query)){
    $data = $result->fetch_array();

    if($data[0] == $password) {
        setcookie('id',base64_encode($name),0,'/');
        accessLogin($name);
    }else{ noLogin(); }

    $result->close();
}else{ noLogin(); }

function accessLogin($name){
    echo "<h1> Welcome " .$name;
}

function noLogin(){
    print "<script language=javascript> alert('없는 회원입니다'); history.back(); </script>";
}
$mysql->close();
