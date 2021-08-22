const express = require('express');
var mongoose = require('mongoose');
mongoose.connect('mongodb://localhost:27017/tests', {useNewUrlParser: true, useUnifiedTopology: true});

function createSchema(db){
    db.on('error', console.error.bind(console, 'connection error'));
    var itemSchema = new mongoose.Schema({
        name: String,
        price: Number
    });
    return mongoose.model('item', itemSchema);
}

function saveItem(item){
    const save = async function(item){
        try{
            return await item.save();
        }catch(err){
            console.log(err);
        }
    }
    return save(item);
}

function getItems(item){

    const find = async function(item){
        try{
            return await item.find();
        }catch(err){
            console.log(err);
        }
    }
    return find(item);
}

function deleteItem(item, id){

    const del = async function(item, id){
        try{
            return await item.deleteOne({_id : id});
        }catch(err){
            console.log(err);
            return err;
        }
    }

    return del(item, id)
}

var db = mongoose.connection;

var item = createSchema(db);
const app = express();
const port = 3001;

app.get('/', (req, res) => {
    res.sendFile("./index.html" ,{root:__dirname})
});

app.get('/get', (req, res) => {
    let response = getItems(item);
    response.then(function(value){
        res.send(value);
    });
});

app.get('/add', (req, res) => {
    let _name = req.query.name;
    var i = new item({name: _name, price: 0});
    let response = saveItem(i);
    response.then(function(value){
        res.send(value);
    })
});

app.get('/delete', (req, res) =>{
    let id = req.query.id;
    let response = deleteItem(item, id);
    response.then(function(value){
        res.send(value);
    })
});

app.listen(port, () => console.log('Running...'));