var OrientDB = require('orientjs');
var server = OrientDB({
    host: 'localhost',
    port: 2480,
    username: 'root',
    password: '1thflatk!'
});
var db = server.use('o2');

var sql = 'SELCET FROM topic';
db.query(sql).then(function(results){
    console.log(results);
});
