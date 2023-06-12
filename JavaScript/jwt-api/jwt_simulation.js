// I had ChatGPT write this

// Simulating jsonwebtoken library

// The secret key used for signing and verifying the token
const secretKey = "mysecretkey";

// Simulating the sign function
function sign(payload, secret) {
  // Create the header
  const header = {
    alg: "HS256", // Algorithm used for signing
    typ: "JWT", // Type of token
  };

  // Encode the header and payload as Base64 strings
  const encodedHeader = base64Encode(JSON.stringify(header));
  const encodedPayload = base64Encode(JSON.stringify(payload));

  // Create the signature using HMAC-SHA256 algorithm
  const signature = hmacSHA256(`${encodedHeader}.${encodedPayload}`, secret);

  // Encode the signature as Base64 string
  const encodedSignature = base64Encode(signature);

  // Combine the encoded header, payload, and signature to form the token
  const token = `${encodedHeader}.${encodedPayload}.${encodedSignature}`;

  return token;
}

// Simulating the verify function
function verify(token, secret) {
  // Split the token into its components: header, payload, and signature
  const [encodedHeader, encodedPayload, encodedSignature] = token.split(".");

  // Decode the header and payload from Base64 strings
  const header = JSON.parse(base64Decode(encodedHeader));
  const payload = JSON.parse(base64Decode(encodedPayload));

  // Recreate the signature using the received header and payload
  const signature = hmacSHA256(`${encodedHeader}.${encodedPayload}`, secret);

  // Decode the received signature from Base64 string
  const decodedSignature = base64Decode(encodedSignature);

  // Compare the recreated signature with the received signature
  const isSignatureValid = signature === decodedSignature;

  return {
    isSignatureValid,
    header,
    payload,
  };
}

// Helper function to encode a string as Base64
function base64Encode(string) {
  return Buffer.from(string).toString("base64");
}

// Helper function to decode a Base64 string
function base64Decode(base64String) {
  return Buffer.from(base64String, "base64").toString("utf-8");
}

// Helper function to create HMAC-SHA256 signature
function hmacSHA256(data, key) {
  const hmac = require("crypto").createHmac("sha256", key);
  hmac.update(data);
  return hmac.digest("hex");
}

// Testing the simulated sign and verify functions
const payload = { userId: 123 };
const token = sign(payload, secretKey);
console.log("Token:", token);

const verification = verify(token, secretKey);
console.log("Verification:", verification);
