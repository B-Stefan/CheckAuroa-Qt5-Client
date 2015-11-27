Card {
   id:currentRatingCard
   anchors.centerIn: parent
   height: Units.dp(100)

   state: "loading"

   states: [
       State {
           name: "loading"
           PropertyChanges { target: currentRatingTxt; opacity: 0 }
           PropertyChanges { target: currentRatingWait; opacity: 1 }
       },
       State {
           name: "ready"
           PropertyChanges { target: currentRatingTxt; opacity: 1 }
           PropertyChanges { target: currentRatingWait; opacity: 0 }
       }
   ]

   CurrentRatingManager {
       id: model
       onReadyChanged: {
           currentRatingCard.state = "ready"
           console.log("yeeeah ready")
       }
   }
   Component.onCompleted: {
       model.refreshRating()
   }

   ProgressCircle {
      id: "currentRatingWait"
      anchors.centerIn: parent

   }

   Text {
       font.pixelSize: 100
       id: "currentRatingTxt"
       anchors.centerIn: parent
       font.pointSize: 25
       text: (model.currentRating.value*100)  + "%"

   }

}