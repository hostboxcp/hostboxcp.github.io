location /softaculous {
    alias /usr/local/hostboxcp/public/softaculous/;

    location ~ /(libraries|setup|templates|locale) {
        deny all;
        return 404;
    }
    location ~ /(.+\.(json|lock|md)) {
        deny all;
        return 404;
    }

    location ~ ^/softaculous/(.*\.php)$ {
        alias /usr/local/hostboxcp/public/softaculous/$1;
        fastcgi_pass unix:/run/php-fpm/default-fpm-81.sock;
        fastcgi_index index.php;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $request_filename;
    }

    location /softaculous/(.+\.(jpg|jpeg|gif|css|png|webp|js|ico|html|xml|txt))$ {
        root /usr/local/hostboxcp/public/softaculous/;
    }
}