location /phppgadmin {
    alias /usr/local/hostboxcp/public/phppgadmin/;
    index index.html index.htm index.php;

    location ~ ^/phppgadmin/(.*\.php)$ {
        alias /usr/local/hostboxcp/public/phppgadmin/$1;
        fastcgi_pass unix:/run/php-fpm/default-fpm-80.sock;
        fastcgi_index index.php;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $request_filename;
    }
}