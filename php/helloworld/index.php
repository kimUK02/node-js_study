<html>
<head>
    <title>Index</title>
</head>
<body>
<?php
$name = $_POST['name'];
$tmp = $_COOKIE['name'];

if ($name === $tmp) {
    echo 'equals';
} else {
    setcookie('name', $name);
    echo 'not equals';
}

?>
</body>
</html>