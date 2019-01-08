<html lang="ko">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>post and echo</title>
</head>
<body>
    <form action='/models/login.php' method="post">
    <label for="input"> username: </label>
    <input name="input" placeholder="input" type="text">
    <br>
    <label for="password"> Password: </label>
    <input name="password" placeholder="password" type="password">
    <br>
    <button type="submit">Login</button>
    </form>
</body>
</html>