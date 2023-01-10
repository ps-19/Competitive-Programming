```
// Basics of starting a server using nodeJS


const express = require('express');
const app = express();
app.use(express.json());
const mongoose = require('mongoose');
const path = require('path');

//
app.use(express.urlencoded({ extended: false }));
const publicDirectoryPath = path.join(__dirname, './public');
app.use(express.static(publicDirectoryPath));
//


const PORT = 3000;

const DB="mongodb+srv://admin:admin@cluster0.93ma7dp.mongodb.net/demos?retryWrites=true&w=majority";


const userSchema = new mongoose.Schema({
    name: {
        type: String,
        required: true
    },
    email: {
        type: String,
        required: true
    }
})

var User = mongoose.model("demos", userSchema); // database schema


mongoose.connect(DB).then(() => {            
    console.log('Database Connected!');
}).catch((error)=>{
    console.log('Not Connected!'+error);
})

app.get('/', (req,res)=>{
    User.find({}).then((result)=>{
        res.send(result);
    }).catch((err)=>{
        res.send("Error found "+err);
    })
})

app.post('/', (req,res)=>{
    console.log(req.body);
    var name=req.body.name;
    var email=req.body.email;
    var user = new User({name,email});
    user.save().then(()=>{
        console.log("Saved !");
    }).catch((error)=>{
        console.log("Not saved !"+error);
    })
    res.send('Hello World');
})

app.put('/', (req,res)=>{
    res.send('Hello World');
    User.updateOne({email: "abc@abc.com"},{$set: {"name": "Rohit Sharma"}}).then((res)=>{
        console.log("Done! No error found: "+res.acknowledged);
    }).catch((error)=>{
        res.send("Error or Not Found " + error)
    })
})

app.delete('/', (req,res)=>{
    User.deleteOne({email: "abc@abc.com"}).then(()=>{
        res.send("Successfully Deleted");
    }).catch((err)=>{
        res.send(err);
    })
})


app.listen(PORT,()=>{
    console.log('Server is running on '+PORT);
})


```
