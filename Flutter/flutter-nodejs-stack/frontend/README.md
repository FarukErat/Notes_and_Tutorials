# Frontend - Flutter

Before running the Flutter frontend, make sure the server is up and running.

1. Set the `serverIp` in the `bcryptHash()` function as stated in the definition.

2. Open the terminal and type the following commands:
   ```
   cd bcrypt_hash
   flutter run -d web-server --web-port 8080 --web-hostname 0.0.0.0
   ```

3. Open the following URL in your browser: `http://$serverIp:8080` (not `http://$serverIp:3013`).
