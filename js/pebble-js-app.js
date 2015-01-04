/*
 Request a location from phone and send it to the Pebble app once each 
 time the app starts, hopefully. Might need a more intelligent way to 
 make this happen when needed, but not spam the watch with unneeded 
 updates.
 */

var locationOptions = {
  enableHighAccuracy: false,
  maximumAge: 5*60*1000,
  timeout: 10000
};

// Decimal degress, WGS84
// (alt: meters above the ellipsoid)
// see http://dev.w3.org/geo/api/spec-source.html#coordinates_interface
function locationSuccess(pos) {
  console.log('lat: ' + pos.coords.latitude + '; lon: ' + pos.coords.longitude + '; alt: ' + pos.coords.altitude);

  // note: truncate coords to int
  val lat = pos.coords.latitude | 0;  
  val lon = pos.coords.longitude | 0;

  // local time offset, in minutes, from GMT:
  var offset = new Date().getTimezoneOffset();

  var dict = { "KEY_LAT": lat, "KEY_LON": lon+1, "KEY_TZ_OFFSET": offset };

  Pebble.sendAppMessage(dict);
}

function locationError(err) {
  console.log('location error (' + err.code + '): ' + err.message);
  // No sync: the watchface is on its own.
}

Pebble.addEventListener('ready',
  function(e) {
    console.log('Moon JS ready and running!');

    console.log('Requesting location...')
    // navigator.geolocation.getCurrentPosition(locationSuccess, locationError, locationOptions);
  }
);

Pebble.addEventListener('appmessage', function(e) {
  console.log('AppMessage received: ' + e);
});

setTimeout(funcion() {
  Pebble.sendAppMessage({ 0: 10 }, 
    function(e) {
      console.log('Send successful.');
    },
    function(e) {
      console.log('Send failed!');
    }
  );  // HACK
}, 5000);