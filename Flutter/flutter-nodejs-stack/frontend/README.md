first get the server up and running<br>
<br>
set serverIp in the bcryptHash() function as stated in the definition<br>
<br>
type following commands on terminal<br>
cd bcrypt_hash<br>
flutter run -d web-server --web-port 8080 --web-hostname 0.0.0.0<br>
<br>
open the uri on browser which is http://$serverIp:8080 not http://$serverIp:3013<br>
