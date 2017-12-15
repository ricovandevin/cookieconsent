(function ($, D, cc) {
    D.behaviors.cookieConsent = {
        attach: function (context, settings) {
            // Get configuration passed in by Drupal.
            var config = D.settings.cookieConsent;

            // Add event listeners to the configuration.
            config.onInitialise = function (status) {
                var type = this.options.type;
                var didConsent = this.hasConsented();
                if (type == 'opt-in') {
                    // The Cookie Consent plugin is not working as expected when in opt-in mode. In opt-in mode
                    // dismissing implies not accepting cookies but hasConsented() always returns true if the status
                    // is dismiss.
                    didConsent = this.getStatus() == cc.status.allow;
                    if (didConsent) {
                        D.cookieConsent.enableCookies(status);
                    }
                    if (!didConsent) {
                        D.cookieConsent.disableCookies(status);
                    }
                }
                if (type == 'opt-out') {
                    if (!didConsent) {
                        D.cookieConsent.disableCookies(status);
                    }
                    if (didConsent) {
                        D.cookieConsent.enableCookies(status);
                    }
                }
            };
            config.onStatusChange = function (status, chosenBefore) {
                var type = this.options.type;
                var didConsent = this.hasConsented();
                if (type == 'opt-in') {
                    // The Cookie Consent plugin is not working as expected when in opt-in mode. In opt-in mode
                    // dismissing implies not accepting cookies but hasConsented() always returns true if the status
                    // is dismiss.
                    didConsent = this.getStatus() == cc.status.allow;
                    if (didConsent) {
                        D.cookieConsent.enableCookies(status, chosenBefore);
                    }
                    if (!didConsent) {
                        D.cookieConsent.disableCookies(status, chosenBefore);
                    }
                }
                if (type == 'opt-out') {
                    if (!didConsent) {
                        D.cookieConsent.disableCookies(status, chosenBefore);
                    }
                    if (didConsent) {
                        D.cookieConsent.enableCookies(status, chosenBefore);
                    }
                }
            };
            config.onRevokeChoice = function () {
                // The revoke button in the Cookie Consent plugin does not have a clear UX. As a visitor you expect
                // that it just shows you info about the cookie policy but in fact it revokes your previous choice.
                // We choose not to use the revoke button this way so we do nothing when this event is triggered.
            };

            // Initialize the Cookie Consent plugin.
            cc.initialise(config);

            // The revoke button is not shown by default. This seems to be a bug. So we need to make it visible
            // ourselves when the banner is hidden. Unfortunately the Cookie Consent plugin does not have a proper API
            // to determine whether or not the banner is currently visible so we need to resort to an ugly check.
            if (!$('.cc-window').is(':visible')) {
                $('.cc-revoke').show();
            }

            // Add an event listener to a custom dismiss link in the banner text. Unfortunately the Cookie Consent
            // plugin has no proper API to change the status so we have no option but to pass through the click event
            // to the actual dismiss button.
            $('.cc-dismiss-link').once('cookieConsent').on('click', function (e) {
                // Using jQuery to trigger the click event on the dismiss button does not work properly so
                // we are using vanilla JavaScript here.
                window.document.getElementsByClassName('cc-btn cc-dismiss')[0].click();
                e.preventDefault();
            });
        }
    };
})(jQuery, Drupal, window.cookieconsent);