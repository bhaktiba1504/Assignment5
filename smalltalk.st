Object subclass: Ride [
    | rideID pickupLocation dropoffLocation distance |

    Ride class >> newWithID: id pickup: pickup dropoff: dropoff distance: dist [
        ^ self new initializeWithID: id pickup: pickup dropoff: dropoff distance: dist.
    ]

    Ride >> initializeWithID: id pickup: pickup dropoff: dropoff distance: dist [
        rideID := id.
        pickupLocation := pickup.
        dropoffLocation := dropoff.  "Changed drop to dropoff"
        distance := dist.
    ]

    Ride >> rideDetails [
        ^ 'Ride ID: ', rideID asString, '
Pickup: ', pickupLocation, '
Dropoff: ', dropoffLocation, '
Distance: ', distance asString, ' miles'.
    ]

    Ride >> fare [
        self subclassResponsibility.
    ]
]

"StandardRide Subclass"
Ride subclass: StandardRide [
    StandardRide >> initialize [
        super initialize.
        "Additional initialization for StandardRide"
    ]

    StandardRide >> fare [
        ^ distance * 2.0.
    ]

    StandardRide >> rideDetails [
        ^ super rideDetails, '
Type: Standard Ride
Fare: $', (self fare) asString.
    ]
]

"PremiumRide Subclass"
Ride subclass: PremiumRide [
    PremiumRide >> initialize [
        super initialize.
        "Additional initialization for PremiumRide"
    ]

    PremiumRide >> fare [
        ^ distance * 3.5.
    ]

    PremiumRide >> rideDetails [
        ^ super rideDetails, '
Type: Premium Ride
Fare: $', (self fare) asString.
    ]
]

"Testing the Ride Sharing System"
| ride1 ride2 rides |

ride1 := StandardRide newWithID: 1 pickup: 'Downtown' dropoff: 'Airport' distance: 10.
ride2 := PremiumRide newWithID: 2 pickup: 'Mall' dropoff: 'Hotel' distance: 5.

rides := { ride1. ride2 }.

"Print the results to the console"
rides do: [ :ride | 
    (ride rideDetails) displayNl.
].
