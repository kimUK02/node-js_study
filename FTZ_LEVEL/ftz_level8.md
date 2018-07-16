# Hackserschool FTZ level8
---
힌트를 보면
~~~
level9의 shadow 파일이 서버 어딘가에 숨어있다.
그 파일에 대해 알려진 것은 용량이 "2700"이라는 것 뿐이다.
~~~
>$ find / -size 2700c 2>/dev/null

을하면 
~~~
/var/www/manual/ssl/ssl_intro_fig2.gif
/etc/rc.d/found.txt
/usr/share/man/man3/IO::Pipe.3pm.gz
/usr/share/man/man3/URI::data.3pm.gz
~~~
가 나오는데 
왠지 txt파일이 수상하다. 그래서 
> $ cd /etc/rc.d
>
> $ cat found.txt

를하면

~~~
level9:$1$vkY6sSlG$6RyUXtNMEVGsfY7Xf0wps:11040:0:99999:7:-1:-1:134549524
~~~
이게나오는데 john the ripper를 이용하여 
>$1$vkY6sSlG$6RyUXtNMEVGsfY7Xf0wps

를 풀면 비밀번호가 나온다,