# Gaimin SDK
Gaimin SDK is an Unreal Engine plugin that acts as a simple interface to our product API and enables users to communicate with the Gaimin backend from inside Unreal Engine using Blueprints.

# Installation
To install the plugin, simply unpack the archive into the `Plugins` folder (create it if it doesn’t exist) inside the project’s root directory.
The resulting file hierarchy should be similar to this:
```
ProjectRoot/
├── ...
├── Plugins
│   └── GaiminSDK
│       ├── GaiminSDK.uplugin
│       └── Source
|           └── ...
└── ...
```

# Usage
To test the plugin’s functionality, create a new Blueprint class

![1](https://user-images.githubusercontent.com/15280154/228606094-1fb957f0-1349-4e60-953e-cc778dd61a6b.png)

of type “Actor”

![2](https://user-images.githubusercontent.com/15280154/228606152-1e0de653-f44b-47e4-bec8-eccdb9deca89.png)

and drag-n-drop it into the scene

![3](https://user-images.githubusercontent.com/15280154/228606155-c7ebecd1-4fe8-4a01-b9db-f5b3539b99ac.png)

To start scripting, double click the newly created blueprint. The Event Editor will open in a new window. Right clicking the empty space in the Event Graph tab shows all available blueprints. Blueprints provided by the plugin are located in the “Gaimin” section:

![4](https://user-images.githubusercontent.com/15280154/228606161-c73cfae8-77ba-470c-8a8c-0932a61aa8f5.png)

Clicking on any item will create the corresponding blueprint. There is a single blueprint for each API call:

![5](https://user-images.githubusercontent.com/15280154/228606165-2bb405f0-2f16-4f09-922d-3c0f20b32ff5.png)

To issue an API call we need to connect a blueprint to an event, in response to which it will execute, and provide the required arguments. For testing purposes, we can use a default “BeginPlay” event that is fired at the start of the game. Here’s an example configuration to get a public key from the Gaimin server:

![6](https://user-images.githubusercontent.com/15280154/228606169-49ce609f-b5fb-4f46-8f8c-496668436e8a.png)

The way it works is, at the start of the game we issue an API call and use the “On Success” blueprint to fire an event when the response is received. The event contains the JSON value of the response which we can convert to object and use in any way we want.

For example, to print the response on the screen, we can do the following:

![7](https://user-images.githubusercontent.com/15280154/228606171-9cff5840-2204-4fae-a50e-e9fe26641a20.png)

This example is similar to the previous one, except that the received JSON value is converted to a string and printed to the screen using the “Print String” blueprint. It should look similar to this:

![8](https://user-images.githubusercontent.com/15280154/228606173-f6e53680-e236-4e60-b46e-3c228abe2ab5.png)

As another example, here’s how to retrieve the player’s token:

![9](https://user-images.githubusercontent.com/15280154/228606175-cbced95f-7169-4deb-938f-f493bb475969.png)

This API call requires an argument (Bearer token) which can be provided by either by pasting the literal text in the input box, or connecting a string input from another blueprint. After the response is received, it is possible to take its fields by using the “Get Object/String/Number” blueprints.

This way, we can, for example, display the user’s GMRX balance on the screen like this:

![10](https://user-images.githubusercontent.com/15280154/228606176-92aa1cd1-d331-4757-bf6d-3cc27fe49e59.png)
![11](https://user-images.githubusercontent.com/15280154/228606180-bb3f1d7b-5167-40a3-8550-78e5ca1d98b9.png)

The last two API blueprints are “Player Tokens” and “Player Tokens Raw” which work in the same way but send responses in different formats. In addition to a player token, they also require the product Id and a list of comma-separated chains. Again, we can simply print the response to test the blueprints:

![12](https://user-images.githubusercontent.com/15280154/228606182-36e6617c-0adc-471d-a449-dee37fa2b926.png)
![13](https://user-images.githubusercontent.com/15280154/228606187-95bcee75-f719-4ed2-884e-de923c28dcf4.png)
