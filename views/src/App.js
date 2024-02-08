import axios from "axios"
import { useState } from "react";

const URL = "http://localhost:8080/";

function App() {
  const [message, setMessage] = useState("");
  const [responseData, setResponseData] = useState("")

  const postMessage = async () =>{
    const response = await axios.post(URL, {
      text: message
    })
    setResponseData(response.data.encryptedMessage)
    setMessage("")
  }
  return (
    <div className="App w-screen min-h-screen bg-slate-800 flex justify-center items-center">
      <form className="w-3/12 h-96 rounded-2xl bg-slate-900 flex justify-center items-center text-lg text-white flex-col gap-3" onSubmit={(e) =>{
        e.preventDefault();
        postMessage();
      }}>
        <input type="text" required autoComplete="off" placeholder="Messagem" name="message" value={message} id="message" className=" focus:outline-0 focus:border-white rounded-lg bg-transparent w-8/12 " onChange={(e)=>{
          setMessage(e.target.value)
        }}/>
        <button type="submit" className="rounded-md border-white border bg-slate-900 hover:bg-slate-950 duration-500 ease-in-out px-3 py-2">Criptografar</button>
        <div className="text-lg text-white">{responseData}</div>
      </form>
    </div>
  );
}

export default App;
