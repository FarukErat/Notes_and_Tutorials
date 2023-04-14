var map;
function initMap() {
  // coordinates of Alanya
  let latitude = 36.5444;
  let longitude = 31.9954;
  map = new google.maps.Map(document.getElementById("map"), {
    center: { lat: latitude, lng: longitude },
    zoom: 8,
  });
}
