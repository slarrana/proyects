# Para ensamblar la imagen:
Docker build -t name .
# Para ejecutar la imagen con autoindex por defecto:
Docker run -ti -p 80:80 -p 443:443 prueba
# Para ejecutar la imagen sin autoindex:
Docker run -ti -p 80:80 -p 443:443 -e autoindex=off prueba