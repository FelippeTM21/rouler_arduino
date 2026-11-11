using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using extOSC;



public class OSCProcess : MonoBehaviour
{
    public OSCReceiver oscReceiver;
    public OSCTransmitter oscTransmitter;
    public Player player;
    // Start is called before the first frame update
    void Start()
    {
        
        oscReceiver.Bind("/rot", TraiterMessageAlpha);
        oscReceiver.Bind("/but", TraiterMessageAlpha);

    }

    // Update is called once per frame
    void Update()
    {
        
    }
    void TraiterMessageAlpha(OSCMessage message)
    {
    }
}
